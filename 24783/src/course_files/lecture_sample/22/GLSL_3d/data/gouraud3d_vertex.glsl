attribute vec3 vertex;
attribute vec4 color;
attribute vec3 normal;

uniform mat4 projection,modelView;
uniform vec3 lightDir;
uniform float ambient,diffuse,specular,specularExponent;

varying vec4 colorOut;

void main()
{
	gl_Position=projection*modelView*vec4(vertex,1.0);

	vec3 nom=normalize((modelView*vec4(normal,0.0)).xyz);
	vec3 lit=normalize(lightDir);

	float diffuseIntensity;
	diffuseIntensity=diffuse*max(0.0,dot(nom,lit));

	vec4 posInView=modelView*vec4(vertex,1.0);
	vec3 viewDir=-normalize(posInView.xyz);
	vec3 midDir=normalize(viewDir+lightDir);

	float specularIntensity;
	specularIntensity=specular*pow(max(0.0,dot(midDir,nom)),specularExponent);

	colorOut=vec4(color.rgb*(ambient+diffuseIntensity),color.a)
            +vec4(specularIntensity,specularIntensity,specularIntensity,0.0);
}
