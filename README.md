bit-map-playground
==================
### Notes
- `int` (or `long`) array in which each element are responsible for 32 positive integers - `arr[0]` for `0` - `31`, `arr[1]` for `32` - `63`...

###
- [海量数据下的去重和查重（一）：BitMap位图法 - 简书](https://www.jianshu.com/p/8d074e8d02aa)
  - ```java
    import java.util.BitSet;

    public class HelloWorld {
            private int[] bigArray;

            public HelloWorld(long size){
                bigArray = new int[(int) (size/ 32 + 1)];
            }

            public void set1(int  num){

                int arrayIndex = num >> 5;
                int bitIndex = num & 31;
                bigArray[arrayIndex] |= 1 << bitIndex;
            }

            public void set0(int  num){
                int arrayIndex = num >> 5;
                int bitIndex = num & 31;
                bigArray[arrayIndex] &= ~(1 << bitIndex);
                System.out.println(get32BitBinString(bigArray[arrayIndex]));
            }

            public boolean isExist(int  num){
                int arrayIndex = num >> 5;
                int bitIndex = num & 31;

                return (bigArray[arrayIndex] & (1 << bitIndex))!=0 ? true : false;
            }




        private static String get32BitBinString(int number) {
            StringBuilder sBuilder = new StringBuilder();
            for (int i = 0; i < 32; i++){
                sBuilder.append(number & 1);
                number = number >>> 1;
            }
            return sBuilder.reverse().toString();
        }

        public static void main(String[] args) {
            int[] arrays = new int[]{1, 2, 35, 22, 56, 334, 245, 2234, 54};

            HelloWorld bigMapTest = new HelloWorld(2234-1);

            for (int i : arrays) {
                bigMapTest.set1(i);
            }
            System.out.println(bigMapTest.isExist(2));
        }

    }
    ```
