import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6

Rectangle {
    Plugin{
        id:mapPlugin
        name:"osm"
        PluginParameter {
                            name: "osm.mapping.providersrepository.disabled"
                            value: "true"
                        }
                        PluginParameter {
                            name: "osm.mapping.providersrepository.address"
                            value: "http://maps-redirect.qt.io/osm/5.8/satellite"
                        }
    }

    Map
    {
        id :mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: Qtpositioning.coordinate( 603974.8382612, 4075424.397654);
        zoomLevel: 15
    }
}
