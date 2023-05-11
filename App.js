import React, { useState, useEffect } from 'react';
import { Text, View, TouchableOpacity, ActivityIndicator } from 'react-native';

const YourApp = () => {
  const [isLoading, setIsLoading] = useState(false);
  const [sensorData, setSensorData] = useState(null);

  const fetchSensorData = async () => {
    setIsLoading(true);

    // Replace ThingsBoard server URL
    const thingsboardUrl = 'https://thingsboard.cs.cf.uk';
    // Replace ThingsBoard device access token
    const accessToken = 'nbEVolyeQcmBxhLHCSqk';

    try {
      // Fetch telemetry data
      const response = await axios.get(
        `${thingsboardUrl}/api/plugins/telemetry/DEVICE/${accessToken}/values/timeseries`,
        {
          params: {
            keys: 'temperature,humidity,light',
          },
        },
      );

      if (response.data) {
        const data = {
          temperature: response.data.temperature[0].value,
          humidity: response.data.humidity[0].value,
          light: response.data.light[0].value,
        };
        setSensorData(data);
      }
    } catch (error) {
      console.error('Error fetching data:', error);
    } finally {
      setIsLoading(false);
    }
  };

  useEffect(() => {
    fetchSensorData();
  }, []);

  return (
    <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
      {isLoading ? (
        <ActivityIndicator size="large" color="#0000ff" />
      ) : (
        <>
          <Text style={{ fontSize: 24, marginBottom: 20 }}>Sensor Data:</Text>
          {sensorData ? (
            <View>
              <Text>Temperature: {sensorData.temperature}°C</Text>
              <Text>Humidity: {sensorData.humidity}%</Text>
              <Text>Light: {sensorData.light} lux</Text>
            </View>
          ) : (
            <Text>No data available</Text>
          )}
          <TouchableOpacity
            style={{
              backgroundColor: 'blue',
              padding: 10,
              borderRadius: 5,
              marginTop: 20,
            }}
            onPress={fetchSensorData}>
            <Text style={{ color: 'white' }}>Refresh Data</Text>
          </TouchableOpacity>
        </>
      )}
    </View>
  );
};

export default YourApp;