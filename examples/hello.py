#!/usr/bin/env python3
from gi.repository import Hello
if __name__ == "__main__":
    h = Hello.World.new("Hello, world!")
    h.print_message()
