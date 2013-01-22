#version 120

uniform mat4 orthoMatrix;
uniform mat4 modelMatrix;

varying vec2 vertPosition;
varying vec2 vertTexCoord;

varying vec2 fragTexCoord;

void main(void)
{
	gl_Position = (orthoMatrix * modelMatrix) * vec4(vertPosition, 0.0, 1.0);
	fragTexCoord = vertTexCoord;
}