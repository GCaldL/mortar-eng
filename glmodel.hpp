/* This file is part of mortar.
 *
 * mortar is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mortar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mortar.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MORTAR_GLMODEL_H
#define MORTAR_GLMODEL_H

#define GL_GLEXT_PROTOTYPES

#include <vector>
#include <GL/gl.h>
#include "model.hpp"

class GLModel {
	public:
		class RenderObject {
			public:
				GLuint elementBuffer;
				GLuint vertexArray;

				GLenum primitiveType;

				int elementCount;

				glm::mat4 transformation;

				Model::Material material;
		};

		GLModel(Model model, GLuint shaderProgram);
		~GLModel();

		GLuint *vertexArrayIds;
		GLuint *vertexBufferIds;
		GLuint *textureIds;

		int vertexBufferCount;
		int textureCount;

		std::vector<RenderObject> renderObjects;
};

#endif
