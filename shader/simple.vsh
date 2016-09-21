#version 130
in vec3 in_Position;
//in vec3 in_Normal;
in vec2 in_texCoord;

out vec2 ex_texCoord;

uniform mat4 transformMatrix, projectMatrix, viewMatrix;

void main(void)
{
//  gl_Position = projectMatrix * transformMatrix  * viewMatrix * vec4(in_Position, 1.);
  gl_Position = projectMatrix * viewMatrix * transformMatrix * vec4(in_Position, 1.);
  ex_texCoord = in_texCoord;
}
