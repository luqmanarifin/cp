buf = gets.split(' ').map(&:to_i)
n, k = buf[0], buf[1]
k -= 1
a = gets.split(' ').map(&:to_i)
count = 0
for i in 0..n-1
  if a[i] >= a[k] && a[i] > 0
    count += 1
  end
end
puts count
