void QuadraticSpline(in vec2 x, in vec2 p_0, in vec2 p_1, in vec2 p_2, out float d)
{
    vec2 E = uv-p_0, F = p_2-2.*p_1+p_0, G = p_1-p_0;
    vec3 coeff = vec3(3.*dot(G,F), 2.*dot(G,G)-dot(E,F), -dot(E,G))/dot(F,F);
    float a = coeff.x, b = coeff.y, c = coeff.z;
    float p = b-a*a/3., q = 2.*a*a*a/27.-a*b/3.+c, dis = q*q/4.+p*p*p/27.,
        tau = a/3.;
    float k1 = -.5*q+sqrt(dis), k2 = -.5*q-sqrt(dis);
    float u = sign(k1)*pow(abs(k1), 1./3.), v = sign(k2)*pow(abs(k2), 1./3.);    
    float t_min = 1.;
    if(dis > 0.)
    {
        t_min = u+v-tau;
        t_min = clamp(t_min, 0.,1.);
    }
    else if(dis < 0.)
    {
        float fac = sqrt(-4./3.*p), arg = -.5*q*sqrt(-27./p/p/p),
            t1 = -fac*cos(acos(arg)/3.+pi/3.)-tau,
            t2 = fac*cos(acos(arg)/3.)-tau,
            t3 = -fac*cos(acos(arg)/3.-pi/3.)-tau;
        t1 = clamp(t1,0.,1.);
        t2 = clamp(t2,0.,1.);
        t3 = clamp(t3,0.,1.);
        float b1 = dist(p_0,p_1,p_2,uv,t1),
            b2 = dist(p_0,p_1,p_2,uv,t2),
            b3 = dist(p_0,p_1,p_2,uv,t3);
        t_min = mix(mix(t1, t2, step(b2, b1)), t3, step(b3, min(b1, b2)));
    } 
    d = dist(p_0,p_1,p_2,uv,t_min);
}
