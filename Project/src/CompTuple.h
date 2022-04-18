#ifndef COMPTUPLE_H
#define COMPTUPLE_H

#include <tuple>

template<size_t I = 0, typename... Tp>
class LessTuple{

public:
    bool operator()(std::tuple<Tp ...> a, std::tuple<Tp ...> b)
    {

        bool ans = true;

        if(std::get<I>(a) == std::get<I>(b)){
            if constexpr(I+1 != sizeof... (Tp)){
                return LessTuple<I+1, Tp...>{}(a,b);
            }
            else
                ans = false;
        }
        else{
            if(std::get<I>(a) < std::get<I>(b))
                ans = true;
            else
                ans = false;
        }

        return ans;
    }

};

template<size_t I = 0, typename... Tp>
class GreaterTuple{

public:
    bool operator()(std::tuple<Tp ...> a, std::tuple<Tp ...> b)
    {

        bool ans = true;

        if(std::get<I>(a) == std::get<I>(b)){
            if constexpr(I+1 != sizeof... (Tp)){
                return GreaterTuple<I+1, Tp...>{}(a,b);
            }
            else
                ans = false;
        }
        else{
            if(std::get<I>(a) > std::get<I>(b))
                ans = true;
            else
                ans = false;
        }

        return ans;
    }

};

#endif // COMPTUPLE_H
