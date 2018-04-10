# export RUBY_THREAD_VM_STACK_SIZE = 200000000

$n, $m, $k = 0, 0, 0
$a = []

def valid?(i, j)
  return 0 <= i && i < $n && 0 <= j && j < $m
end

def dfs(x, y)
  if !valid?(x, y) || $a[x][y] != '.'
    return
  end
  $a[x][y] = 'L'
  dfs x + 1, y
  dfs x - 1, y
  dfs x, y + 1
  dfs x, y - 1
  return if $k == 0
  $a[x][y] = 'X'
  $k -= 1;
end

buf = gets.split(' ').map(&:to_i)
$n, $m, $k = buf[0], buf[1], buf[2]

# puts $n, $m, $k

for i in 0..$n-1
  $a[i] = gets
end

for i in 0..$n-1
  for j in 0..$m-1
    dfs i, j if $a[i][j] == '.'
  end
end

for i in 0..$n-1
  for j in 0..$m-1
    $a[i][j] = '.' if $a[i][j] == 'L'
  end
  puts $a[i]
end
