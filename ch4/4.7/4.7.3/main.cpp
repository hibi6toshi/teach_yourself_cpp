void featureX();
void featureY();
void featureZ();

namespace submodule {
  void featureX();
  void featureY();
  void featureZ();
}

namespace module_a {
  void featureX();
  void featureY();
  namespace submodule {
    void featureX();
    void featureY();
  }
}

namespace module_b {
  void featureX();
  void featureY();
  namespace submodule {
    void featureX();
    void featureY();
  }

  namespace A {
    void featureX();
    namespace submodule {
      void featureX();
    }

    void caller() {
      featureX(); // module_b::A::featureX()

      // module_b::A::submodule::featureX() 
      submodule::featureX();

      featureY(); // module_b::featureY()

      // module_b::submodule::featureY()
      module_b::submodule::featureY(); 

      featureZ(); // グローバル名前空間のfeatureZ()

      ::submodule::featureZ();
    }
  }
}
