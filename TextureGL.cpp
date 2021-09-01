#include "stb_truetype.h"
#include "stb_image_write.h"
#include "stb_image.h"

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Bdv {
	class TextureGL {
	public:
		int loadFromFile(const std::string& filename) {
			int width;
			int height;
			int comp;
			stbi_uc* pixels = stbi_load(filename.c_str(), &width, &height, &comp, 4);

			if (pixels == NULL) {
				// TODO: Log this..
				return 0;
			}
			GLuint m_TextureID;

			glGenTextures(1, &m_TextureID);
			glBindTexture(GL_TEXTURE_2D, m_TextureID);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

			stbi_image_free(pixels);

			return m_TextureID;
		}
	};
}