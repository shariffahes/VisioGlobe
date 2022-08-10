package com.reactlibrary;

import android.content.Context;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import androidx.fragment.app.Fragment;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

import com.visioglobe.visiomoveessential.VMEMapView;
import com.visioglobe.visiomoveessential.listeners.VMELifeCycleListener;

public class MapViewFragment extends Fragment {
    MapView mapViewInstance;
    private VMEMapView mMapView;
    private boolean showOverlay;
    private boolean shouldDisplayPrompt;

    public MapViewFragment(boolean showOverlay, boolean shouldDisplayPrompt) {
        this.showOverlay = showOverlay;
        this.shouldDisplayPrompt = shouldDisplayPrompt;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup parent, Bundle savedInstanceState) {
        super.onCreateView(inflater, parent, savedInstanceState);
        mapViewInstance = new MapView(this.getContext(), shouldDisplayPrompt);
        mMapView = mapViewInstance.getVMEMapView();
        mMapView.setLifeCycleListener(mLifeCycleListener);
        mMapView.setSelectorViewVisible(showOverlay);
        return mapViewInstance;
    }

    @Override
    public void onPause() {
        super.onPause();
        mMapView.onPause();
    }

    @Override
    public void onResume() {
        super.onResume();
        mMapView.onResume();
    }

    private VMELifeCycleListener mLifeCycleListener = new VMELifeCycleListener()
    {
        @Override
        public void mapDidInitializeEngine(VMEMapView mapView) {
            String lFilePath = extractFromAssetsAndGetFilePath("artifika_regular.ttf");
            if(lFilePath != null){
                mapView.setMapFont(lFilePath);
            }
        }
    };

    private String extractFromAssetsAndGetFilePath(String pFileName) {
        Context ctx = getContext();
        if(ctx != null){
            File f = new File(getContext().getCacheDir() + "/" + pFileName);
            if (!f.exists()) {
                try {
                    InputStream is = getContext().getAssets().open(pFileName);
                    int size = is.available();
                    byte[] buffer = new byte[size];
                    is.read(buffer);
                    is.close();
                    FileOutputStream fos = new FileOutputStream(f);
                    fos.write(buffer);
                    fos.close();
                }
                catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            return f.getPath();
        }
        return null;
    }
}