public class h_solve {
    public static void main(String[] args) {
        for (long i=0, p=0; i<(1L<<62)+(1L<<61) && p<50000; i+=30727L*62233) {
            int h = (int)(i ^ (i >>> 32));
            h ^= (h >>> 20) ^ (h >>> 12);
            h = h ^ (h >>> 7) ^ (h >>> 4);
            int q = h&((1<<16)-1);
            if (q==0) { ++p; System.out.println(i); }
        }
    }
}
