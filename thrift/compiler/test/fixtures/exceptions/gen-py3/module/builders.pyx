#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
cdef class Banal_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _module_types.Banal

    def __iter__(self):
        pass

cdef class Fiery_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _module_types.Fiery

    def __iter__(self):
        yield "message", self.message

cdef class Serious_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _module_types.Serious

    def __iter__(self):
        yield "sonnet", self.sonnet

