#!/usr/bin/env python3
"""
Script to extract C++ code blocks from markdown files that contain a main function 
and save them in a folder structure based on section headings.
Usage: python extract_cpp_snippets.py <markdown_file>
"""

import re
import os
import sys
from pathlib import Path

def sanitize_filename(text):
    """
    Convert text to a valid filename/folder name by removing/replacing invalid characters.
    """
    # Remove or replace invalid filename characters
    text = re.sub(r'[<>:"/\\|?*]', '', text)
    # Replace spaces and other whitespace with underscores
    text = re.sub(r'\s+', '_', text)
    # Remove multiple consecutive underscores
    text = re.sub(r'_+', '_', text)
    # Remove leading/trailing underscores and dots
    text = text.strip('_.')
    # Limit length to avoid filesystem issues
    if len(text) > 50:  # Shorter for folder names
        text = text[:50]
    # Ensure it's not empty
    if not text:
        text = "unnamed"
    return text

def extract_sections_with_cpp_code(markdown_content):
    """
    Extract C++ code blocks along with their section context.
    Returns a list of tuples: (section_hierarchy, code_block)
    """
    lines = markdown_content.split('\n')
    results = []
    current_sections = {}  # Track current section at each level
    i = 0
    
    while i < len(lines):
        line = lines[i]
        
        # Check for section headers (# ## ### etc.)
        header_match = re.match(r'^(#+)\s+(.+)', line)
        if header_match:
            level = len(header_match.group(1))
            title = header_match.group(2).strip()
            
            # Update current sections at this level and clear deeper levels
            current_sections[level] = title
            # Clear deeper levels
            keys_to_remove = [k for k in current_sections.keys() if k > level]
            for k in keys_to_remove:
                del current_sections[k]
        
        # Check for C++ code block start
        elif line.strip() == '```cpp':
            # Find the end of the code block
            code_lines = []
            i += 1
            while i < len(lines) and lines[i].strip() != '```':
                code_lines.append(lines[i])
                i += 1
            
            code = '\n'.join(code_lines)
            
            # Build section hierarchy (as a list)
            section_hierarchy = []
            for level in sorted(current_sections.keys()):
                section_hierarchy.append(current_sections[level])
            
            if not section_hierarchy:
                section_hierarchy = ["unknown_section"]
            
            results.append((section_hierarchy, code))
        
        i += 1
    
    return results

def clean_code_block(code):
    """
    Clean up the code block by removing extra whitespace and ensuring proper formatting.
    """
    # Remove leading/trailing whitespace
    code = code.strip()
    
    # Ensure the code ends with a newline
    if not code.endswith('\n'):
        code += '\n'
    
    return code

def save_code_blocks_with_folder_structure(sections_and_code, base_output_dir="cpp_snippets"):
    """
    Save code blocks in a folder structure based on section hierarchy.
    """
    saved_files = []
    file_counters = {}  # Track duplicate filenames within each folder
    
    for section_hierarchy, code in sections_and_code:
        # Use all but the last section as folder path
        folder_parts = [sanitize_filename(part) for part in section_hierarchy[:-1]]
        filename_base = sanitize_filename(section_hierarchy[-1]) if section_hierarchy else "unnamed"
        
        # Create folder path
        if folder_parts:
            folder_path = os.path.join(base_output_dir, *folder_parts)
        else:
            folder_path = base_output_dir
        
        # Create directories
        Path(folder_path).mkdir(parents=True, exist_ok=True)
        
        # Handle duplicate filenames within the same folder
        folder_key = folder_path
        if folder_key not in file_counters:
            file_counters[folder_key] = {}
        
        if filename_base in file_counters[folder_key]:
            file_counters[folder_key][filename_base] += 1
            filename = f"{filename_base}_{file_counters[folder_key][filename_base]}.cpp"
        else:
            file_counters[folder_key][filename_base] = 0
            filename = f"{filename_base}.cpp"
        
        # Full file path
        filepath = os.path.join(folder_path, filename)
        
        # Write the file
        cleaned_code = clean_code_block(code)
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(cleaned_code)
        
        # Calculate relative path for display
        relative_path = os.path.relpath(filepath, base_output_dir)
        
        saved_files.append(filepath)
        print(f"Saved: {relative_path}")
        print(f"  Section: {' -> '.join(section_hierarchy)}")
        print(f"  Lines: {len(cleaned_code.splitlines())}")
        print()
    
    return saved_files

def main():
    if len(sys.argv) != 2:
        print("Usage: python extract_cpp_snippets.py <markdown_file>")
        print("Example: python extract_cpp_snippets.py tutorial.md")
        print("\nThis will create a folder structure like:")
        print("cpp_snippets/")
        print("├── Chapter_1_Basics/")
        print("│   ├── Hello_World.cpp")
        print("│   └── Variables.cpp")
        print("└── Chapter_2_Advanced/")
        print("    └── Classes.cpp")
        sys.exit(1)
    
    markdown_file = sys.argv[1]
    
    # Check if file exists
    if not os.path.isfile(markdown_file):
        print(f"Error: File '{markdown_file}' not found.")
        sys.exit(1)
    
    try:
        # Read the markdown file
        with open(markdown_file, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # Extract C++ code blocks with their section context
        sections_and_code = extract_sections_with_cpp_code(content)
        
        if not sections_and_code:
            print("No C++ code blocks with main function found in the markdown file.")
            return
        
        print(f"Found {len(sections_and_code)} C++ code block(s) with main function\n")
        
        # Save code blocks with folder structure
        saved_files = save_code_blocks_with_folder_structure(sections_and_code)
        
        print(f"Successfully extracted {len(saved_files)} C++ files with folder structure to 'cpp_snippets/' directory")
        
    except Exception as e:
        print(f"Error processing file: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
