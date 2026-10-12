# Export the version given in project metadata
from importlib import metadata

from _testghacookiecutter import add_one

__version__ = metadata.version(__package__)
del metadata


def one_plus_one():
    return add_one(1)
