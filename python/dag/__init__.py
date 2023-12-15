import os
import shutil
import tarfile
import tempfile
from importlib import resources
from pathlib import Path

import numpy as np

from .dag import *

def data_files(key: str) -> list:
    temp_dir = tempfile.mkdtemp()
    data_files_dict = dict(
        matrix_graphs="matrix_graphs.tar.gz",
        bitarray_graphs="bitarray_graphs.tar.gz",
    )
    cwd = Path.cwd()
    with resources.path("dag.data", data_files_dict[key]) as tarball_file:
        os.chdir(tarball_file.parent)
        tarball = tarfile.open(tarball_file)
        tarball_members = [tarball_file.parent / f.name for f in tarball.getmembers()]
        temp_files = [Path(temp_dir) / f.name for f in tarball_members]
        tarball.extractall()
        tarball.close()
        for tarball_member, temp_file in zip(tarball_members, temp_files):
            shutil.copy(tarball_member, temp_file)
            tarball_member.unlink()
    os.chdir(cwd)
    return [
        file for file in temp_files if file.suffix == ".npy"
    ]

