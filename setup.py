from skbuild import setup
import os
import pybind11


setup(
    name='citest',
    version="0.0.75",
    author='Your Name',
    author_email='your@email.com',
    description='Add description here',
    long_description='',
    classifiers=[
        "Programming Language :: Python :: 3",
        "Operating System :: OS Independent",
        "License :: OSI Approved :: MIT License",
    ],
    zip_safe=False,
    packages=["citest"],
    cmake_args=[
        "-DBUILD_TESTING=OFF",
        "-DBUILD_DOCS=OFF",
        f"-DCMAKE_PREFIX_PATH={os.path.dirname(pybind11.__file__)}",
    ],
    package_dir={"": "python"},
    cmake_install_dir="python/citest",
)
