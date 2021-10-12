import numpy

def rotate(vector, axis, angle):
    a = axis / numpy.linalg.norm(axis)
    d = vector.dot(a) * a
    r = vector - d
    r2 = numpy.cross(a, r)
    r_rotated = r*numpy.cos(angle) + r2*numpy.sin(angle)
    return r_rotated + d

axis = numpy.array([0,1,0])
angle = 8*numpy.pi/6

vector = numpy.array([0,0,1])
print(numpy.around(rotate(vector, axis, angle),decimals=4))