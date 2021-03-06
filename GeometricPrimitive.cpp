#include "GeometricPrimitive.h"

GeometricPrimitive::GeometricPrimitive()
{

}
GeometricPrimitive::GeometricPrimitive(Transformation objW, Transformation wObj, Shape* s, Material* m)
{
    // implement copy constructors
    objToWorld = objW;
    worldToObj = wObj;
    shape = s;
    mat = m;
}
bool GeometricPrimitive::intersect(Ray& ray, float* thit, Intersection* in)
{
    Ray oray = worldToObj*ray;
    LocalGeo olocal;
    if (!shape->intersect(oray, thit, &olocal))  return false;
    in->primitive = this;
    in->local = objToWorld*olocal;
    return true;
}
bool GeometricPrimitive::intersectP(Ray& ray)
{
    Ray oray = worldToObj*ray;
    return shape->intersectP(oray);
}
void GeometricPrimitive::getBRDF(LocalGeo& local, BRDF* brdf)
{
    material->getBRDF(local, brdf);
}
