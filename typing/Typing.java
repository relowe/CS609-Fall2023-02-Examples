public class Typing
{
  public static void main(String [] args) {
    double x;
    int y;
    char c;

    // java is more strongly typed than c & c++
    x = 1.5;
    y = (int) x;
    System.out.println(y);

    y = 1;
    x = y;
    System.out.println(x);

    y = 65;
    c = (char)y;
    System.out.println(c);
  }    
}