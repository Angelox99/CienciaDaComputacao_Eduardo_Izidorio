public class Main {
    public static void main(String[] args){
        Ferrari minhaFerrari = new Ferrari();
        Camaro meuCamaro = new Camaro();
        Fusca meuFusca = new Fusca();

        Rota rota = new Rota();

        rota.irParaUfrr(minhaFerrari);

        rota.irParaUfrr(meuCamaro);

        rota.irParaUfrr(meuFusca);

        
    }
}
