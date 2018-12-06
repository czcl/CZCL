#!/usr/bin/env python
import sys
import struct
import binascii
import base64

if len(sys.argv) > 1:
    print base64.b64encode(binascii.a2b_hex(sys.argv[1]))


