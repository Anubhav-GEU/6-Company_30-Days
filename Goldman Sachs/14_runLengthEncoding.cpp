string encode(string src)
{     
  //Your code here 
  string ans = "";
  int n = src.length();
  int counter = 0;
  
  for (int i=0; i<n;) {
      counter = 0;
      int j=i;
      
      while (src[i] == src[j]) {
          counter++;
          j++;
      }
      ans+=src[i];
      ans+=to_string(counter);
      i=j;
  }
  return ans;
}     
