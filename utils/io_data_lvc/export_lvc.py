import bpy

SCALE = 10.0
def edgeValues(edge, mesh, matrix):
    fv = []
    for verti in edge.vertices:
        fv.append((matrix * mesh.vertices[verti].co)[:])
    return fv


def edgeToLine(edge):
        return " ".join([("%.6f %.6f" % (v[0]*SCALE, v[2]*SCALE)) for v in edge] + ["\n"])



def write(filepath):
    scene = bpy.context.scene

    edges = []
    for obj in bpy.context.selected_objects:
        try:
            me = obj.to_mesh(scene, True, "PREVIEW")
        except:
            me = None

        if me is not None:
            matrix = obj.matrix_world.copy()
            for edge in me.edges:
                ev = edgeValues(edge, me, matrix)
                edges.append(ev)
        else:
            print("Error, no s'ha pogut exportar el mesh")
        bpy.data.meshes.remove(me)

    file = open(filepath, "w")
    for edge in edges:
        file.write(edgeToLine(edge))
    file.close()
