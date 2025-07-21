# LinuxCNC integration
Given below are the steps to integrate this project into LinuxCNC.

1. Download the source from the official LinuxCNC repository:
```sh
wget -O linuxcnc-2.9.4.zip https://github.com/LinuxCNC/linuxcnc/archive/refs/tags/v2.9.4.zip
unzip linuxcnc-2.9.4.zip
```

This tool was tested on v2.9.4, so watch out for breaking changes if using a
newer version!

2. Clone this repository inside `linuxcnc-2.9.4/src/emc/sterp` and run the
integration script.
```sh
git clone https://github.com/s-mv/gcode-plus-plus.git src/emc/sterp
cd src/emc/sterp
chmod +x integrate.sh
./integrate.sh
```

3. Go to back to `linuxcnc-2.9.4/src` and build!
```sh
cd ../../
chmod +x ./autogen.sh
./autogen.sh
./configure --with-realtime=uspace
make
```

We're almost done.

4. Run LinuxCNC to ensure that it's working.
```
cd ..
./scripts/rip-environment linuxcnc
```

## Using HAL and INI parameters

In order to use HAL/INI parameters the syntax is:
```
#hal(...)
```
and
```
#ini(...)
```

