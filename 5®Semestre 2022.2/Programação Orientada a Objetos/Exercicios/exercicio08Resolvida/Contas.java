class Contas{
    public static void main(String[] args) throws ValorInvalidoException{

        Conta c= new ContaCorrente();
        Conta cc= new ContaCorrente();
        Conta cp= new ContaPoupança();

        c.Deposita(1000);
        cc.Deposita(1000);
        cp.Deposita(1000);

        Atualizador a = new Atualizador(0.10);

        Banco BancoJu = new Banco(3);

        BancoJu.Adiciona(c);
        BancoJu.Adiciona(cc);
        BancoJu.Adiciona(cp);


        for(int b=0 ; b < BancoJu.Pegatotalcontas() ; b++){
            System.out.println("ID: "+ (1+b));
            a.roda(BancoJu.PegaConta(b));
        }
        
           System.out.println("\nSaldo total: " + a.getSaldoTotal());

        }

}
