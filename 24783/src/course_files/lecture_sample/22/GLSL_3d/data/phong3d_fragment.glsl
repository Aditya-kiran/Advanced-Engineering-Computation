varying vec4 colorOut;
varying vec3 normalOut;
varying vec3 vertexOut;

uniform mat4 projection,modelView;
uniform vec3 lightDir;
uniform float ambient,diffuse,specular,specularExponent;

void main()
{
	vec3 nom=normalize((modelView*vec4(normalOut,0.0)).xyz);
	vec3 lit=normalize(lightDir);

	float diffuseIntensity;
	diffuseIntensity=diffuse*max(0.0,dot(nom,lit));

	vec4 posInView=modelView*vec4(vertexOut,1.0);
	vec3 viewDir=-normalize(posInView.xyz);
	vec3 midDir=normalize(viewDir+lightDir);

	float specularIntensity;
	specularIntensity=specular*pow(max(0.0,dot(midDir,nom)),specularExponent);

	gl_FragColor=vec4(colorOut.rgb*(ambient+diffuseIntensity),colorOut.a)
  		          +vec4(specularIntensity,specularIntensity,specularIntensity,0.0);
}
