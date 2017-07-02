#version 150


uniform vec2 u_res;
uniform float u_time;
uniform float metaballs[360];

void main(){

    float x = gl_FragCoord.x;
    float y = gl_FragCoord.y;
    float v = 0.0;
    //Loop through uniform array
    for (int i = 0; i < 360; i+=3) {
        float dx = metaballs[i] - x;
        float dy = metaballs[i+1] - y;
        float r = metaballs[i+2];
        //Metaball equation
        v += r*r/(dx*dx + dy*dy);
    }
    if (v > 1.0) {
        gl_FragColor = vec4( x/u_res.y,0.6, y/u_res.x, 1.0);
   } else {
        gl_FragColor = vec4(0.2, 0.2, 0.2, 1.0);
   }
}





