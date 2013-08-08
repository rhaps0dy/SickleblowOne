
bl_info = {
    "name": "Col.lisio per nivells Sickleblow (.lvc)",
    "author": "Adria Garriga Alonso",
    "version": (0, 1),
    "blender": (2, 68, 0),
    "location": "File > Import-Export > Col.lisio Nivell Sickleblow (.lvc) ",
    "description": "Import-Export Col.lisio Nivell Sickleblow",
    "warning": "",
    "wiki_url": "http://www.sickleblow.com",
    "tracker_url": "http://www.sickleblow.com",
    "category": "Import-Export"}

if "bpy" in locals():
    import imp
    if "export_lvc" in locals():
        imp.reload(export_lvc)
else:
    import bpy

from bpy.props import StringProperty, BoolProperty
from bpy_extras.io_utils import ExportHelper

class LvcExporter(bpy.types.Operator, ExportHelper):
    """Export .lvc Sickleblow Level Collision data"""
    bl_idname = "export_data.lvc"
    bl_label = "Export LVC"

    filename_ext = ".lvc"
    filter_glob = StringProperty(default="*.lvc", options={'HIDDEN'})

    def execute(self, context):
        from . import export_lvc
        export_lvc.write(self.filepath)

        return {'FINISHED'}


def menu_export(self, context):
    self.layout.operator(LvcExporter.bl_idname, text="Sickleblow Level Collision data (.lvc)")


def register():
    bpy.utils.register_module(__name__)

    bpy.types.INFO_MT_file_export.append(menu_export)


def unregister():
    bpy.utils.unregister_module(__name__)

    bpy.types.INFO_MT_file_export.remove(menu_export)

if __name__ == "__main__":
    register()

