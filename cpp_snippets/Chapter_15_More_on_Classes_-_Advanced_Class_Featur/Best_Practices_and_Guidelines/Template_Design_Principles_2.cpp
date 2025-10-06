template <typename Func, typename... Args>
auto wrapper(Func&& f, Args&&... args) -> decltype(f(std::forward<Args>(args)...)) 
{
    // Do something before/after
    return f(std::forward<Args>(args)...);
}
