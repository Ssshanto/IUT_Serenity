struct Matrix{
  vector<vector<int>>Mat = vector<vector<int>>(n,vector<int>(n));
    //memset(Mat,0,sizeof(Mat));
  Matrix operator *(const Matrix& other){
    Matrix product;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
          int temp=((long long)(Mat[i][k]%mod)*((long long)other.Mat[k][j]%mod))%mod;
          product.Mat[i][j]=(product.Mat[i][j]%mod+temp%mod)%mod; 
        }
      }
    }
    return product;
  }
};
Matrix MatExpo(Matrix a,int p){
  Matrix product;
  for(int i=0;i<n;i++) product.Mat[i][i]=1;
  while(p>0){
    if(p%2) product=product*a;
    p/=2;
    a=a*a;
  }
  return product;
}