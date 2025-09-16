# generated from rosidl_generator_py/resource/_idl.py.em
# with input from armor_interface:msg/ArmorPoints.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ArmorPoints(type):
    """Metaclass of message 'ArmorPoints'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('armor_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'armor_interface.msg.ArmorPoints')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__armor_points
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__armor_points
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__armor_points
            cls._TYPE_SUPPORT = module.type_support_msg__msg__armor_points
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__armor_points

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ArmorPoints(metaclass=Metaclass_ArmorPoints):
    """Message class 'ArmorPoints'."""

    __slots__ = [
        '_left_top_x',
        '_left_top_y',
        '_left_bottom_x',
        '_left_bottom_y',
        '_right_bottom_x',
        '_right_bottom_y',
        '_right_top_x',
        '_right_top_y',
    ]

    _fields_and_field_types = {
        'left_top_x': 'int32',
        'left_top_y': 'int32',
        'left_bottom_x': 'int32',
        'left_bottom_y': 'int32',
        'right_bottom_x': 'int32',
        'right_bottom_y': 'int32',
        'right_top_x': 'int32',
        'right_top_y': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.left_top_x = kwargs.get('left_top_x', int())
        self.left_top_y = kwargs.get('left_top_y', int())
        self.left_bottom_x = kwargs.get('left_bottom_x', int())
        self.left_bottom_y = kwargs.get('left_bottom_y', int())
        self.right_bottom_x = kwargs.get('right_bottom_x', int())
        self.right_bottom_y = kwargs.get('right_bottom_y', int())
        self.right_top_x = kwargs.get('right_top_x', int())
        self.right_top_y = kwargs.get('right_top_y', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.left_top_x != other.left_top_x:
            return False
        if self.left_top_y != other.left_top_y:
            return False
        if self.left_bottom_x != other.left_bottom_x:
            return False
        if self.left_bottom_y != other.left_bottom_y:
            return False
        if self.right_bottom_x != other.right_bottom_x:
            return False
        if self.right_bottom_y != other.right_bottom_y:
            return False
        if self.right_top_x != other.right_top_x:
            return False
        if self.right_top_y != other.right_top_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def left_top_x(self):
        """Message field 'left_top_x'."""
        return self._left_top_x

    @left_top_x.setter
    def left_top_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'left_top_x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'left_top_x' field must be an integer in [-2147483648, 2147483647]"
        self._left_top_x = value

    @builtins.property
    def left_top_y(self):
        """Message field 'left_top_y'."""
        return self._left_top_y

    @left_top_y.setter
    def left_top_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'left_top_y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'left_top_y' field must be an integer in [-2147483648, 2147483647]"
        self._left_top_y = value

    @builtins.property
    def left_bottom_x(self):
        """Message field 'left_bottom_x'."""
        return self._left_bottom_x

    @left_bottom_x.setter
    def left_bottom_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'left_bottom_x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'left_bottom_x' field must be an integer in [-2147483648, 2147483647]"
        self._left_bottom_x = value

    @builtins.property
    def left_bottom_y(self):
        """Message field 'left_bottom_y'."""
        return self._left_bottom_y

    @left_bottom_y.setter
    def left_bottom_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'left_bottom_y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'left_bottom_y' field must be an integer in [-2147483648, 2147483647]"
        self._left_bottom_y = value

    @builtins.property
    def right_bottom_x(self):
        """Message field 'right_bottom_x'."""
        return self._right_bottom_x

    @right_bottom_x.setter
    def right_bottom_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'right_bottom_x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'right_bottom_x' field must be an integer in [-2147483648, 2147483647]"
        self._right_bottom_x = value

    @builtins.property
    def right_bottom_y(self):
        """Message field 'right_bottom_y'."""
        return self._right_bottom_y

    @right_bottom_y.setter
    def right_bottom_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'right_bottom_y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'right_bottom_y' field must be an integer in [-2147483648, 2147483647]"
        self._right_bottom_y = value

    @builtins.property
    def right_top_x(self):
        """Message field 'right_top_x'."""
        return self._right_top_x

    @right_top_x.setter
    def right_top_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'right_top_x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'right_top_x' field must be an integer in [-2147483648, 2147483647]"
        self._right_top_x = value

    @builtins.property
    def right_top_y(self):
        """Message field 'right_top_y'."""
        return self._right_top_y

    @right_top_y.setter
    def right_top_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'right_top_y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'right_top_y' field must be an integer in [-2147483648, 2147483647]"
        self._right_top_y = value
