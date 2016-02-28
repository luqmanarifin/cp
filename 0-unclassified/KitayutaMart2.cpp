class KitayutaMart2 {
public:
  int numBought(int k, int t) {
    int num = t / k;
    num++;
    for(int i = 0; i < 31; i++) {
      if(num == (1 << i)) {
        return i;
      }
    }
    return 0;
  }
};