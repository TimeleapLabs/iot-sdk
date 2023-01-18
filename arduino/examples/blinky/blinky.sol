// SPDX-License-Identifier: MIT
pragma solidity ^0.8.17;

contract Blinky {
    event Blink(uint8 led);

    /**
     * emit a `Blink` event. This event is picked up
     * and indexed by Kenshi Deep Index, and later
     * is queried by the IoT device.
     */
    function blink(uint8 led) external {
        emit Blink(led);
    }
}
