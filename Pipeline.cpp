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

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Model.cpp"

namespace Bdv {
	class Pipeline {
	private:
		std::vector<GLuint> vaoList;
		std::vector<GLuint> vboList;
		std::vector<int*> textures;
		std::vector<std::vector<int*>> vboPointers;

		GLuint* CreateVAO() {
			GLuint vao[1];
			glGenVertexArrays(1, vao);
			vaoList.push_back(vao[0]);
			return vao;
		}

		void BindBufferVBO(GLuint* indexes) {
			GLuint vbo[1];
			glGenBuffers(1, vbo);
			vboList.push_back(vbo[0]);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[0]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);
		}

		void UnbindVAO() {
			glBindVertexArray(0);
		}

		void UseVAO(GLuint vao) {
			glBindVertexArray(vao);
		}

		void PushVBOData(int attributeNumber, int coordSize, GLfloat* buffer) {
			GLuint vboId[1];
			glGenBuffers(1, vboId);
			vboList.push_back(vboId[0]);
			glBindBuffer(GL_ARRAY_BUFFER, vboId[0]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(buffer), buffer, GL_STATIC_DRAW);
			// 3 coordinates for 3d vectors
			glVertexAttribPointer(attributeNumber, coordSize, GL_FLOAT, false, 0, 0);
			// unbinding VBO
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void UpdateVBOData(GLuint vboId, int attributeNumber, int coordSize, GLfloat* buffer) {
			glBindBuffer(GL_ARRAY_BUFFER, vboId);
			glBufferData(GL_ARRAY_BUFFER, sizeof(buffer), buffer, GL_STATIC_DRAW);
			glVertexAttribPointer(attributeNumber, coordSize, GL_FLOAT, false, 0, 0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

	public:
		Bdv::Model* LoadDataToVAO(GLfloat* positions, GLfloat* textures, GLuint* indexes, GLfloat* colors) {
			GLuint* vao = this->CreateVAO();
			this->BindBufferVBO(indexes);
			this->PushVBOData(0, 3, positions);
			this->PushVBOData(1, 2, textures);
			this->PushVBOData(2, 3, colors);
			this->UnbindVAO();

			return new Bdv::Model(vao[0], sizeof(indexes)/sizeof(indexes[0]));
		}
	};
}