#version 140

uniform sampler2D texture;

in vec2 fragTexCoord;

void main(void)
{
	//gl_FragColor = fragColor;
	gl_FragColor = texture2D(texture, fragTexCoord);
	//gl_FragColor = vec4(1, 1, 0, 1);
}