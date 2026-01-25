
class IInterface
{
public:
  virtual void monAPI1() = 0; // Methode abstraite pure car = 0
  virtual void monAPI2() = 0 // Methode abstraite pure car = 0
  {
    // En C++, une methode abstraite peut avoir une implementation par defaut
  }
  virtual void monAPI3() // Methode virtuelle non pure, surcharge optionnelle
  {
    // Implementation par defaut
  }
}; // <= Rappel: erreur en haut d'un fichier

class MonImplem : public IInterface // Heritage avec public pour dire "est un"
{
public:
  void monAPI1() override
  {
    // Mon implem'
  }
  void monAPI2() override
  {
    IInterface::monAPI2(); // Appel de l'implem par defaut
    // + mon implem'
  }
  virtual void monApi3() // Faux mais valide, definition d'une nouvelle methode
  {
    // Ma surchage
  }
  void monApi3 override() // Faux mais erreur compil, monApi3 n'existe pas au dessus
  {
    // Ma surchage
  }
};

// Allocation sur la pile :
MonImplem instance1;
MonImplem instance1Erreur(); // Declare une fonction instance1Erreur

// Allocation dynamique (sur le tas) :
std::unique_ptr<IInterface> instanceATraversInterface;
instanceATraversInterface = std::make_unique<IInterface>();
auto laMeme = std::make_unique<IInterface>();

// Changement de possesseur de unique_ptr
std::unique_ptr<IInterface> recupInstance;
recupInstance = instanceATraversInterface; // Erreur de compil, copie interdite
recupInstance = std::move(instanceATraversInterface); // Ok, move explicite le fait que l'on passe la possession