public class Banco{

    private Conta[] contas;
    private int limite;
    private static int contascriadas=0;

    public Banco(int limite){
      this.limite=limite;
      contas= new Conta[this.limite];
    }

    public void Adiciona(Conta c){
        if(contascriadas < limite){
         contas[contascriadas] = c;
         contascriadas++;
        }else{
         System.out.println("TODAS AS VAGAS PREENCHIDAS");
        }
    }

    public Conta PegaConta(int x){
        if(x<limite){
            return contas[x];
        }else{
            System.out.println("Conta inexistente");
            return null;
        }
    }

    public int Pegatotalcontas(){
        return this.limite;
    }

}