export module App.UserTranslatedKernel;

export import SteelRT.Data.View;


export
void kernel_ro_region(data::view<1, float> a);

export
void kernel_rw_region(data::view<1, float> a);
