// message.h (Handles JSON serialization/deserialization)
#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <nlohmann/json.hpp>
#include "utils.h"

using json = nlohmann::json;

class Message {
public:
    std::string type;  // e.g., "login", "message", "logout", "error"
    std::string username;
    std::string content;

    // Serialize to JSON string
    std::string serialize() const {
        json j;
        j["type"] = type;
        j["username"] = username;
        j["content"] = content;
        return j.dump();
    }

    // Deserialize from JSON string
    static Message deserialize(const std::string& data) {
        try {
            json j = json::parse(data);
            Message msg;
            msg.type = j.value("type", "");
            msg.username = j.value("username", "");
            msg.content = j.value("content", "");
            return msg;
        } catch (const std::exception& e) {
            log_error("JSON parse error: " + std::string(e.what()));
            return Message{"error", "", "Invalid message"};
        }
    }
};

#endif // MESSAGE_H
