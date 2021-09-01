#pragma once

#include "json.hpp"
using json = nlohmann::json;

#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/matrix.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <functional>
#include <typeinfo>

#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Make sure to include windows before glfw
#ifdef _WIN32
#include <windows.h>
#undef DeleteFile
#undef CopyFile
#undef CreateFile
#undef GetSaveFileName
#undef GetOpenFileName
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>

