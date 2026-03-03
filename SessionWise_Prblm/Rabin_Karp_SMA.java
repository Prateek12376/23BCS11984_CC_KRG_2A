public class Main
{
    public static int Hash(String s){
        int d = 256;
        int mod = 1000000007;
        long hash = 0;
    
        for(int i=0;i<s.length();i++){
            hash = (hash * d + s.charAt(i)) % mod;
        }
    
        return (int)hash;
    }
	public static void main(String[] args) {
		String s = "abcabacbabc";
		String p = "acb";
		
		int ph = Hash(p);
		int i=0;
		int j=p.length()-1;
		int ans =0;
		while(j<s.length()){
		    int sh = Hash(s.substring(i,j+1));
		    if(sh==ph){
		        ans = i;
		        break;
		    }
		    else{
		        i++;
		        j++;
		    }
		}
		System.out.println(ans);
	}
}
