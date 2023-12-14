
from setuptools import find_packages
from setuptools import setup
from pathlib import Path

setup(
    author='Andy Stokely',
    name='dag',
    install_requires=[],
    platforms=['Linux',
               'Unix', ],
    python_requires=">=3.9",
    py_modules=[str(Path.cwd() / "dag/dag")],
    packages=find_packages() + [''],
    zip_safe=False,
    package_data={
        '': [
            str(Path.cwd() / "dag/_libpython_dag.so")
        ]
    },
)
