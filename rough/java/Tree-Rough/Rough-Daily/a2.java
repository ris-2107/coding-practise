import java.util.ArrayDeque;

public class a2 {
    public static void main(String[] args) {
        System.out.println(checkValid("{{{}}"));
    }

    static Boolean checkValid(String str) {

        ArrayDeque<Character> st = new ArrayDeque<>();

        for (int i = 0; i < str.length(); i++) {
            char s = str.charAt(i);
            if (s == '{' || s == '(' || s == '[')
                st.push(s);

            else {
                if (st.isEmpty())
                    return false;
                if (validBracketComb(st.peek(), s) == false)
                    return false;
                else
                    st.pop();
            }
        }
        return st.isEmpty();
    }

    static Boolean validBracketComb(char c1, char c2) {
        return ((c1 == '[' && c2 == ']') || (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}'));
    }

}
