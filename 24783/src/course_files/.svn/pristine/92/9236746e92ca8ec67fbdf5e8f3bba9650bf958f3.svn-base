attribute vec3 vertex;
attribute vec4 color;
attribute float pointSize;

uniform mat4 projection,modelView;
uniform float sizeInPixel;
uniform float sizeIn3d;
uniform float windowHeight;

varying vec4 colorOut;

void main()
{
	gl_Position=projection*modelView*vec4(vertex,1.0);

	vec4 shifted;
	shifted=modelView*vec4(vertex,1.0);
	shifted.y=shifted.y+pointSize;
	shifted=projection*shifted;

	float dy=(shifted.y/shifted.w-gl_Position.y/gl_Position.w)*windowHeight/2.0;

	gl_PointSize=pointSize*sizeInPixel+dy*sizeIn3d;
	colorOut=color;
}
