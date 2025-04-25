#include <iostream> 
#include <string>
#include <vector> // Ajout de l'inclusion manquante pour std::vector
using namespace std;

class Livre {
private:
    string titre;
    string auteur;
    int annee;

public:
    Livre(int a, string t, string au) {
        titre = t;
        auteur = au;
        annee = a;
    }

    Livre() {
        titre = "Inconnu";
        auteur = "Inconnu";
        annee = 0;
    }

    string getTitre() const { // Ajout de const
        return titre;
    }
    string getAuteur() const { // Ajout de const
        return auteur;
    }
    int getAnnee() const { // Ajout de const
        return annee;
    }

    void setTitre(string t) {
        titre = t;
    }
    void setAuteur(string au) {
        auteur = au;
    }
    void setAnnee(int a) {
        annee = a;
    }

    void afficher() const { // Ajout de const
        cout << "   Titre   : " << titre << endl;
        cout << "   Auteur  : " << auteur << endl;
        cout << "   Annee   : " << annee << endl;
    }
};

class bibliotheque {
private:
    vector<Livre> livres; // Correction : Livre avec majuscule

public:
    void ajouterLivre(const Livre& livre) {
        livres.push_back(livre); // Correction : push_back
    }

    void afficheLivres() {
        if (livres.empty()) { // Correction : livres au lieu de liveres
            cout << "La bibliothèque est vide." << endl;
        } else {
            for (int i = 0; i < livres.size(); i++) { // Correction : livres au lieu de liveres
                cout << " ------ Le livre " << i << " -------" << endl;
                livres[i].afficher();
                cout << "------------------------" << endl;
            }
        }
    }

    void chercherLivreParTitre(const string& titre) const {
        for (const auto& livre : livres) { // Correction : livres au lieu de liveres
            if (livre.getTitre() == titre) {
                cout << "Livre trouvé:" << endl;
                livre.afficher();
                return;
            }
        }
        cout << "Livre non trouvé." << endl;
    }

    void retirerLivreParTitre(const string& titre) {
        for (auto it = livres.begin(); it != livres.end(); ++it) { // Correction : livres au lieu de liveres
            if (it->getTitre() == titre) {
                livres.erase(it);
                cout << "Livre retiré." << endl;
                return;
            }
        }
        cout << "Livre non trouvé." << endl;
    }
}; // Correction : ajout du point-virgule après la classe

int main() {
    Livre l1(1997, "Pouvoir du moment présent", "Eckhart Tolle");
    Livre l2(2014, "Zero to One", "Peter Thiel");
    Livre l3(2009, "Start with Why", "Simon Sinek");

    bibliotheque biblio;

    biblio.ajouterLivre(l1);
    biblio.ajouterLivre(l2);
    biblio.ajouterLivre(l3);

    cout << "Affichage des livres dans la bibliothèque:" << endl;
    biblio.afficheLivres();
    cout << endl;

    cout << "Recherche d'un livre par titre: 'Zero to One'" << endl;
    biblio.chercherLivreParTitre("Zero to One");
    cout << endl;

    cout << "Retrait d'un livre par titre: 'Start with Why'" << endl;
    biblio.retirerLivreParTitre("Start with Why");
    cout << endl;

    cout << "Affichage des livres après retrait:" << endl;
    biblio.afficheLivres();
    cout << endl;

    cout << "Ajout d'un nouveau livre:" << endl;
    Livre l4(2021, "Atomic Habits", "James Clear");
    biblio.ajouterLivre(l4);
    cout << "Livre ajouté." << endl;
    cout << endl;

    cout << "Affichage des livres après ajout:" << endl;
    biblio.afficheLivres();
    cout << endl;

    cout << "Recherche d'un livre par titre: 'Atomic Habits'" << endl;
    biblio.chercherLivreParTitre("Atomic Habits");
    cout << endl;

    cout << "Retrait d'un livre par titre: 'Pouvoir du moment présent'" << endl;
    biblio.retirerLivreParTitre("Pouvoir du moment présent");
    cout << endl;

    cout << "Affichage des livres après retrait:" << endl;
    biblio.afficheLivres();
    cout << endl;

    return 0;
}