cp linuxcnc/sterp_example.can ../../../configs/sim/axis/sterp_examples.can
cp linuxcnc/sterp_cmds.hal ../../../configs/sim/axis/sterp_cmds.hal
cp linuxcnc/sterp.ini ../../../configs/sim/axis/sterp.ini

cd ../..

MAKEFILE=Makefile

if ! grep -q 'emc/sterp \\' "$MAKEFILE"; then
    cp "$MAKEFILE" "$MAKEFILE.bak"
    sed -i '/emc\/tooldata \\/a\    emc/sterp \\' "$MAKEFILE"
fi

echo "Integration successful!"
