#version 120

uniform mat4 matrix;

attribute vec3 vertPosition;
attribute vec2 vertTexCoord;

varying vec2 fragTexCoord;

void main(void)
{
    //gl_Position = (modelMatrix * orthoMatrix) * vec4(vertPosition, 1.0);
    gl_Position = matrix * vec4(vertPosition, 1.0);
    fragTexCoord = vertTexCoord;
}
