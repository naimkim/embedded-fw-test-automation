import json
import subprocess
import pytest
import tempfile
import os

CONFIG = "test/test_config.json"

def run_c_test(raw):
    hex_data = ",".join(str(b) for b in raw)
    code = f"""
    #include <stdio.h>
    #include "firmware/utils.h"

    int main() {{
        uint8_t data[] = {{{hex_data}}};
        Packet pkt;
        return parse_packet(data, sizeof(data), &pkt);
    }}
    """

    with tempfile.TemporaryDirectory() as tmp:
        c_file = os.path.join(tmp, "test.c")
        with open(c_file, "w") as f:
            f.write(code)

        cmd = [
            "gcc",
            "-Ifirmware",
            "firmware/utils.c",
            c_file,
            "-o",
            os.path.join(tmp, "a.out"),
        ]
        subprocess.check_call(cmd)
        result = subprocess.run([os.path.join(tmp, "a.out")])
        return result.returncode

@pytest.mark.parametrize("case", json.load(open(CONFIG))["tests"])
def test_packet(case):
    ret = run_c_test(case["raw"])
    assert ret == case["expected"]
