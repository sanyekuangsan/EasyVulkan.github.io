#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <span>
#include <memory>
#include <functional>
#include <concepts>
#include <format>
#include <chrono>
#include <numeric>
#include <numbers>

//GLM
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

//stb_image.h
#include <stb_image.h>

//Vulkan
#include <vulkan/vulkan.h>
#pragma comment(lib, "vulkan-1.lib")

template<typename T>
class arrayParameter {
    T* pArray = nullptr;
    size_t count = 0;
public:
    arrayParameter() = default;
    arrayParameter(T& data) :pArray(&data), count(1) {}
    template<size_t elementCount>
    arrayParameter(T(&data)[elementCount]) : pArray(data), count(elementCount) {}
    arrayParameter(T* pData, size_t elementCount) :pArray(pData), count(elementCount) {}
    //Getter
    T* Pointer() const { return pArray; }
    size_t Count() const { return count; }
    //Const Function
    T& operator[](size_t index) const { return pArray[index]; }
    T* begin() const { return pArray; }
    T* end() const { return pArray + count; }
};
#define ExecuteOnce(...) { static bool executed = false; if (executed) return __VA_ARGS__; executed = true; }