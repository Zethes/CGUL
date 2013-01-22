#version 140
#extension GL_ARB_explicit_attrib_location : enable

uniform mat4 orthoMatrix;
uniform mat4 modelMatrix;

layout (location = 0) in vec2 vertPosition;
in vec2 vertTexCoord;

out vec2 fragTexCoord;

void main(void)
{
	gl_Position = (orthoMatrix * modelMatrix) * vec4(vertPosition, 0.0, 1.0);
	fragTexCoord = vertTexCoord;
}