x_file = "b1.out"
y_file = "b2_try.out"

with open(x_file, "r") as x:
  with open(y_file, "r") as y:
    x_lines = [row for row in x.readlines()]
    y_lines = [row for row in y.readlines()]
    if len(x_lines) != len(y_lines):
      print "wrong length"
    else:
      for i, val in enumerate(x_lines):
        x_tokens = x_lines[i].split(" ")
        y_tokens = y_lines[i].split(" ")
        # print x_tokens[2], y_tokens[2]
        x_ada = x_tokens[2] != "-1"
        y_ada = y_tokens[2] != "-1"
        if x_ada != y_ada:
          print "differ at line %d" % i
