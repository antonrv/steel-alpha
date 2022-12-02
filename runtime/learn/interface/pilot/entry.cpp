  // XXX XXX MOVED TO LAB/NATIVE/pilot.cpp XXX XXX 
  // XXX XXX MOVED TO LAB/NATIVE/pilot.cpp XXX XXX 
  // XXX XXX MOVED TO LAB/NATIVE/pilot.cpp XXX XXX 
  // XXX XXX MOVED TO LAB/NATIVE/pilot.cpp XXX XXX 

// App Graph and Plat Graph TODO

import SteelRT.Util.Native;

import SteelRT.Learn.Interface.Pilot;


int main(int argc, const char** argv) {


  using native_cfg = util::native< >; // TODO


  try {

    // Arguments, whether to open existing weights, rnd seed kind, save when finish, alphas, etc...

    learn::intf::pilot::master<native_cfg> pilotMaster( );

    pilotMaster.run();
    
    pilotMaster.tear_down();

  } catch (const std::runtime_error& rte) {

    std::cout << "PILOT ::: Got runtime error " << rte.what() << std::endl;

  } catch (const std::logic_error& le) {

    std::cout << "PILOT ::: Got logic error " << le.what() << std::endl;

  } catch (...) {

    std::cout << "PILOT ::: Unknown error caught in entry" << std::endl;
  }

  std::cout << "PILOT ::: Exit" << std::endl;

  return 0;
}
