from skbuild import setup
import os
import pybind11


setup(
    packages=["testghacookiecutter"],
    package_dir={"": "python"},
    zip_safe=False,
    cmake_args=[
        "-DBUILD_TESTING=OFF",
        "-DBUILD_DOCS=OFF",
        f"-DCMAKE_PREFIX_PATH={os.path.dirname(pybind11.__file__)}",
    ],
    cmake_install_dir="python/testghacookiecutter",
)
